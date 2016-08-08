using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Timers;

namespace Cabinet.access
{
    class interventiiPacient
    {
        dbAccess da = new dbAccess();
        public DataSet InterventiiPacient(long idPacient)
        
            {
                SqlParameter[] parametri = new SqlParameter[1];
                parametri[0] = new SqlParameter("@idPacient", idPacient);
              
                return da.ExecuteDataSet(DALHelper.Connection, "afisareInterventiiPacient", parametri);
            }
        

    }
}
