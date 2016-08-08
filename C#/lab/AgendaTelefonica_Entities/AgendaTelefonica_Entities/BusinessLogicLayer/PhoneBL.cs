using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgendaTelefonica_Entities.Entities;
using AgendaTelefonica_Entities.DataAccessLayer;
using AgendaTelefonica_Entities.Exceptions;

namespace AgendaTelefonica_Entities.BusinessLogicLayer
{
    class PhonesBL
    {
        internal List<Phone> GetPhonesForPerson(Person persoana)
        {
            PhoneDAL telefoaneDAL = new PhoneDAL();
            return telefoaneDAL.GetAllPhonesForPerson(persoana);
        }

        internal void AddPhone(Phone telefon)
        {
            if (String.IsNullOrEmpty(telefon.PhoneNumber))
            {
                throw new AgendaException("Numarul de telefon nu poate sa lipseasca");
            }
            if (telefon.PersonID == null)
            {
                throw new AgendaException("Trebuie precizat cui ii apartine numarul");
            }
            PhoneDAL telefoaneDAL = new PhoneDAL();
            telefoaneDAL.AddPhone(telefon);
            if (telefon.PhoneID == null)
            {
                throw new AgendaException("Persoana are deja acest nr de telefon!");
            }
        }

        internal void DeletePhone(Phone telefon)
        {
            //if (telefon.PhoneID == null)
            //{
            //    throw new AgendaException("Numarul de telefon trebuie sa aiba un identificator");
            //}
            PhoneDAL telefoaneDAL = new PhoneDAL();
            telefoaneDAL.DeletePhone(telefon);
        }
    }
}
