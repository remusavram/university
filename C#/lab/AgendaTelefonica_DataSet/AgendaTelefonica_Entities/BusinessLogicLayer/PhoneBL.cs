using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgendaTelefonica_Entities.DataAccessLayer;
using AgendaTelefonica_Entities.Exceptions;
using System.Data;

namespace AgendaTelefonica_Entities.BusinessLogicLayer
{
    class PhonesBL
    {
        PhoneDAL telefoaneDAL = new PhoneDAL();
        internal DataSet GetPhonesForPerson(int personID)
        {
            return telefoaneDAL.GetAllPhonesForPerson(personID);
        }

        internal DataSet GetPhoneByID(int phoneID)
        {
            return telefoaneDAL.GetPhoneByID(phoneID);
        }

        internal DataSet SavePhone(int phoneID, int personID, string phoneNumber, string description)
        {
            if (String.IsNullOrEmpty(phoneNumber))
            {
                throw new AgendaException("Numarul de telefon nu poate sa lipseasca");
            }
            if (personID == null)
            {
                throw new AgendaException("Trebuie precizat cui ii apartine numarul");
            }
            return telefoaneDAL.SavePhone(phoneID, personID, phoneNumber, description);
        }

        internal void DeletePhone(int phoneID)
        {
            telefoaneDAL.DeletePhone(phoneID);
        }
    }
}
