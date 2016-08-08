using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using Cabinet.access;

namespace Cabinet.BusinessLogicLayer
{
    class sumaIncasata_BL
    {
        sumaIncasataMedic lista = new sumaIncasataMedic();

        public DataSet suma_incasata(int idMedic)
        {
            return lista.Suma(idMedic);          
            
        }
    }
}


