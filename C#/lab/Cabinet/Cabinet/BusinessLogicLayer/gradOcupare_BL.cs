using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using Cabinet.access;

namespace Cabinet.BusinessLogicLayer
{
    class gradOcupare_BL
    {
      gradOcupare lista = new gradOcupare();

        public DataSet castig_Medic(int idMedic, DateTime dataStart, DateTime dataEnd)
        {
            return lista.GradDeOcupare(idMedic,dataStart,dataEnd);          

        }
    }
}
