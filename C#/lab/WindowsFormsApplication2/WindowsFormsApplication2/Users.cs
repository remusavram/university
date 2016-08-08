using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.Xml.Linq;
using System.IO;
using System.Windows.Forms;

namespace WindowsFormsApplication2
{

    public class Users
    {

        public  string xmlUsers;
        public XDocument xmlData;
        XmlDocument doc = new XmlDocument();
        private string userAvatar = Path.GetDirectoryName(Application.ExecutablePath) + "\\userImg";

        public Users(string xmlDoc)
        {

            if(!File.Exists(xmlDoc))
                File.Create(Path.GetDirectoryName(Application.ExecutablePath)+"\\"+xmlDoc);
           xmlData = XDocument.Load(xmlDoc);
           this.xmlUsers = xmlDoc;
           doc.Load(xmlDoc);

        }

        public List<string> getAllUsers()
        {
            
            List<string> listUsernames = new List<string>();
            var users = from user in this.xmlData.Descendants("user")
                        select new
                        {
                            username = user.Element("username").Value,
                            
                        };
            foreach (var user in users)
            {
                listUsernames.Add(user.username);
            }
            return listUsernames;
        }

        public string getAvatar(string username)
        {
            XElement  image = (from images in xmlData.Descendants("user")
                                where images.Element("username").Value == username
                                select images).FirstOrDefault();
            if(!Directory.Exists(userAvatar))
                Directory.CreateDirectory(userAvatar);
            string img =  userAvatar + "/" +image.Element("imagename").Value;
            if(File.Exists(img))
                return img;
            else
                return null;
 
        }

        public bool checkUser(string username)
        {
            XElement user = (from users in xmlData.Descendants("user")
                              where users.Element("username").Value == username
                              select users).FirstOrDefault();
            if (user != null)
                return false;
            return true;
        }

        public void addUser(string username, string imagename)
        {
            XElement newUser = new XElement("user",
                new XElement("username", username),
                new XElement("imagename", imagename),
                new XElement("statistics",
                    new XElement("all", "0|0"),
                    new XElement("rivers", "0|0"),
                    new XElement("mountains", "0|0"),
                    new XElement("cities", "0|0"),
                    new XElement("cars", "0|0"),
                    new XElement("movies", "0|0"))
            );
            xmlData.Element("usersDetails").Add(newUser);
            xmlData.Save(xmlUsers); 
        }

        public void deleteUser(string username)
        {
            XElement image = (from images in xmlData.Descendants("user")
                              where images.Element("username").Value == username
                              select images).FirstOrDefault();
            string img = userAvatar + "/" + image.Element("imagename").Value;
            
            if (File.Exists(img))
              File.Delete(img);

            var delUser = (from xml in xmlData.Descendants("user")
                           where xml.Element("username").Value == username
                           select xml).FirstOrDefault();
            delUser.Remove();
            xmlData.Save(xmlUsers);
        }

        public void addstatistics(string cat, string username, string type)
        {
            string val;
            string[] data;
            int play, win;
            XElement user = (from users in xmlData.Descendants("user")
                              where users.Element("username").Value == username
                              select users).FirstOrDefault();
            
            val = user.Element("statistics").Element(cat).Value;
            data = val.Split('|');
            play = int.Parse(data[0]) + 1;
            if (type == "win")
            {
                win = int.Parse(data[1])+1;
            }
            else 
            {
                win = int.Parse(data[1]);
            }

            
            user.Element("statistics").Element(cat).Value = play.ToString() + "|" + win.ToString();
            xmlData.Save(xmlUsers);

        }

        public string getStatistics(string username, string category)
        {
            XElement user = (from users in xmlData.Descendants("user")
                             where users.Element("username").Value == username
                             select users).FirstOrDefault();
            return user.Element("statistics").Element(category).Value;

        }

        public void saveGame(string username, int timp, string cuvatGasit, string cuvant, int greseli, string literefolosite, int lvl)
        {
            XElement user = (from users in xmlData.Descendants("user")
                             where users.Element("username").Value == username
                             select users).FirstOrDefault();
            user.Element("savedgame").Element("time").Value = timp.ToString();
            user.Element("savedgame").Element("cuvantgasit").Value = cuvatGasit;
            user.Element("savedgame").Element("cuvant").Value = cuvant;
            user.Element("savedgame").Element("greseli").Value = greseli.ToString();
            user.Element("savedgame").Element("literefolosite").Value = literefolosite;
            user.Element("savedgame").Element("level").Value = lvl.ToString(); ;
            xmlData.Save(xmlUsers);

        }

    }  
}
