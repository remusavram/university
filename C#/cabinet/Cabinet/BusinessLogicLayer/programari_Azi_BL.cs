using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using Cabinet.access;

namespace Cabinet.BusinessLogicLayer
{
    class programari_Azi_BL
    {
        programari_Azi lista = new programari_Azi();

        public DataSet Afisare_programari( int idMedic)
        {
            return lista.Afisare_programari(idMedic);               

        }
    }
}
