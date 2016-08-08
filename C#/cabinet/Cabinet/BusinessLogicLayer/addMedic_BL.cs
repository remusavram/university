using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using Cabinet.access;

namespace Cabinet.BusinessLogicLayer
{
    class addMedic_BL
    {
        addMedic lista = new addMedic();

        public String AdaugareMedic( int idMedic, string nume)
        {
            return lista.add_Medic(idMedic, nume);               

        }
    }
}
