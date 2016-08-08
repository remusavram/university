using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using Cabinet.access;

namespace Cabinet.BusinessLogicLayer
{
    class castigMedic_BL
    {
      castigMedic_cl lista = new castigMedic_cl();

        public DataSet castig_Medic(int idMedic)
        {
            return lista.castigMedic(idMedic);          

        }
    }
}
