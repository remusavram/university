using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgendaTelefonica_Entities.DataAccessLayer;
using AgendaTelefonica_Entities.Exceptions;
using System.Data;

namespace AgendaTelefonica_Entities.BusinessLogicLayer
{
    public class PersonsBL
    {
        PersonDAL persoanaDAL = new PersonDAL();
        public DataSet GetAllPersons()
        {
            return persoanaDAL.GetAllPersons();
        }

        internal DataSet GetAllPersonsWithoutPhone()
        {
            return persoanaDAL.GetAllPersonsWithNoPhone();
        }

        internal DataSet GetPersonByID(int personID)
        {
            return persoanaDAL.GetPersonByID(personID);
        }

        internal DataSet SavePerson(int personID, string name, string address)
        {
            if (name.Trim() == String.Empty)
            {
                throw new AgendaException("Numele persoanei trebuie sa fie precizat");
            }
            return persoanaDAL.SavePerson(personID, name, address);
        }

        internal void DeletePerson(int personID)
        {
            if (personID == null)
            {
                throw new AgendaException("Nu se poate sterge persoana cu id neprecizat");
            }
            PersonDAL persoanaDAL = new PersonDAL();
            persoanaDAL.DeletePerson(personID);
        }
    }
}
