using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using Cabinet.access;

namespace Cabinet.BusinessLogicLayer
{
    class addPacient_BL
    {
        addPacient lista = new addPacient();

        public String AdaugarePacient( long cnp, string nume, string adresa)
        {
            return lista.add_Pacient(cnp, nume,adresa);               

        }
    }
}
