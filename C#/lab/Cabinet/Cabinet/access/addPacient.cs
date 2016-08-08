using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;

namespace Cabinet.access
{
    class addPacient
    {
        dbAccess daPacient = new dbAccess();
        public String add_Pacient(long cnp, string nume, string adresa)
        {
            SqlParameter[] paramsList= new SqlParameter[3];
            paramsList[0] = new SqlParameter("@cnp", cnp);
            paramsList[1] = new SqlParameter("@nume", nume);
            paramsList[2] = new SqlParameter("@adresa", adresa);

            return daPacient.ExecuteNonQuery(DALHelper.Connection, "addPacient", paramsList);
            
        }

    }
}
