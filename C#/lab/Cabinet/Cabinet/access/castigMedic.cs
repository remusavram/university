using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Timers;

namespace Cabinet.access
{
    class castigMedic_cl
    {
        dbAccess da = new dbAccess();
        public DataSet castigMedic(int idMedic)
        {
            SqlParameter[] parametri = new SqlParameter[1];
            parametri[0] = new SqlParameter("@idMedic", idMedic);

            return da.ExecuteDataSet(DALHelper.Connection, "CastigulMediculuiPeLuna", parametri);
        }
    }
}
