using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;
using System.Timers;

namespace Cabinet.access
{
    class interventiiVechi
    {
        dbAccess daInterventii = new dbAccess();
        public DataSet Afisare_interventii(int idInterventie, DateTime data)
        {
            
            SqlParameter[] paramsList= new SqlParameter[2];
            paramsList[0] = new SqlParameter("@id", idInterventie);
            paramsList[1] = new SqlParameter("@data", data.Date);
           // System.Windows.Forms.MessageBox.Show(Convert.ToString(data.Date));
            return daInterventii.ExecuteDataSet(DALHelper.Connection, "afisareInterventii", paramsList);
        }

    }
}
