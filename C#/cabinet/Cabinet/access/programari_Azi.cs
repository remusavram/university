using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;

namespace Cabinet.access
{
    class programari_Azi
    {
        dbAccess daProgramari = new dbAccess();
        public DataSet Afisare_programari(int idMedic)
        {
            SqlParameter[] paramsList= new SqlParameter[1];
            paramsList[0] = new SqlParameter("@idMedic", idMedic);
          

            return daProgramari.ExecuteDataSet(DALHelper.Connection, "afisProgAzi", paramsList);
        }

    }
}
