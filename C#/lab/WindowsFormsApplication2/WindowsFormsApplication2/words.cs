using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Xml;
using System.Xml.Linq;
using System.Xml.XPath;

namespace WindowsFormsApplication2
{
    class words
    {
        public string xmlWords;
        XmlDocument doc = new XmlDocument();
        public words(string xmlDoc)
        {
            this.xmlWords = xmlDoc;       
            doc.Load(xmlWords);
        }

        public string getRandomWord()
        {
           
            var allWords = doc.SelectNodes("/words/word");
            string[] word = allWords.Cast<XmlNode>()
                             .Select(n => n.InnerText)
                             .ToArray();

            for (int i = 0; i < allWords.Count; i++)
            {
                word[i] = allWords[i].InnerText.ToUpper();

            }
            Random rand = new Random();
            return word[rand.Next(0, word.Length - 1)];
        }
        
        public string getRandomWordCat(string cat)
        {
            var Words = doc.SelectNodes("/words/word[@cat='"+cat+"']");
            string[] word = Words.Cast<XmlNode>()
                             .Select(n => n.InnerText)
                             .ToArray();

            for (int i = 0; i < Words.Count; i++)
            {
                word[i] = Words[i].InnerText.ToUpper();
               
            }

            Random rand = new Random();
            return word[rand.Next(0, word.Length - 1)];
        }


        public string[] getCategories()
        {
            XmlNodeList elemList = doc.GetElementsByTagName("word");
            List<string> cat = new List<string>();
            for (int i = 0; i < elemList.Count; i++)
            {
               cat.Add(elemList[i].Attributes["cat"].InnerText);
            }
            return cat.Distinct().ToArray();
          
            
        }

 
    }
}
