using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Timers;
using System.Data.SqlTypes;


namespace Cabinet.access
{
    class gradOcupare
    {
        dbAccess daDurataInterventii = new dbAccess();
        public DataSet GradDeOcupare(int idMedic, DateTime dataStart, DateTime dataEnd)
        {

            SqlParameter[] paramsList = new SqlParameter[3];
            paramsList[0] = new SqlParameter("@idMedic", idMedic);
            paramsList[1] = new SqlParameter("@dataStart", dataStart.Date);
            paramsList[2] = new SqlParameter("@dataEnd", dataEnd.Date);
           
            // System.Windows.Forms.MessageBox.Show(Convert.ToString(data.Date));
            return daDurataInterventii.ExecuteDataSet(DALHelper.Connection, "durataInterventiilorPeOPerioada", paramsList);
            // return cmd.Params
        }

    }
}

