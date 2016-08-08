using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgendaTelefonica_Entities.Entities;
using AgendaTelefonica_Entities.DataAccessLayer;
using AgendaTelefonica_Entities.Exceptions;

namespace AgendaTelefonica_Entities.BusinessLogicLayer
{
    class PersonsBL
    {
        internal List<Person> GetAllPersons()
        {
            PersonDAL persoanaDAL = new PersonDAL();
            return persoanaDAL.GetAllPersons();
        }

        internal List<Person> GetAllPersonsWithoutPhone()
        {
            PersonDAL persoaneDAL = new PersonDAL();
            return persoaneDAL.GetAllPersonsWithNoPhone();
        }

        internal void AddPerson(Person persoana)
        {
            if (persoana.Name.Trim() == String.Empty)
            {
                throw new AgendaException("Numele persoanei trebuie sa fie precizat");
            }
            PersonDAL persoaneDAL = new PersonDAL();
            persoaneDAL.AddPerson(persoana);
        }

        internal void DeletePerson(Person persoana)
        {
            if (persoana.PersonID == null)
            {
                throw new AgendaException("Nu se poate sterge persoana cu id neprecizat");
            }
            PersonDAL persoanaDAL = new PersonDAL();
            persoanaDAL.DeletePerson(persoana);
        }

        internal void ModifyPerson(Person persoana)
        {
            if (persoana.PersonID == null)
            {
                throw new AgendaException("Trebuie prezizat identificatorul persoanei");
            }
            if (String.IsNullOrEmpty(persoana.Name))
            {
                throw new AgendaException("Trebuie precizat numele persoanei");
            }
            PersonDAL persoaneDAL = new PersonDAL();
            persoaneDAL.ModifyPerson(persoana);
        }
    }
}
