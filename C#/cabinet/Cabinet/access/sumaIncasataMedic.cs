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
    class sumaIncasataMedic
    {
        dbAccess daSuma = new dbAccess();
        public DataSet Suma(int idMedic)
        {

            SqlParameter[] paramsList = new SqlParameter[1];
            paramsList[0] = new SqlParameter("@idMedic", idMedic);

            // System.Windows.Forms.MessageBox.Show(Convert.ToString(data.Date));
            
            return daSuma.ExecuteDataSet(DALHelper.Connection, "SumaIncasataDeMedicDeLaFiecarePacient", paramsList);
            // return cmd.Params
        }

    }
}

