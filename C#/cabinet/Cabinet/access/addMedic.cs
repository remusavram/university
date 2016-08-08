using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;

namespace Cabinet.access
{
    class addMedic
    {
        dbAccess daMedic = new dbAccess();
        public String add_Medic(int idMedic, string nume)
        {
            SqlParameter[] paramsList= new SqlParameter[2];
            paramsList[0] = new SqlParameter("@idMedic", idMedic);
            paramsList[1] = new SqlParameter("@nume", nume);

            return daMedic.ExecuteNonQuery(DALHelper.Connection, "addMedic", paramsList);
            
        }

    }
}
