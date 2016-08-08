using System;
using System.Collections.Generic;
//using System.Linq;
using System.Text;
using System.Configuration;
using System.Data.SqlClient;

namespace Cabinet.access
{
    static class DALHelper
    {
        private static readonly String connectionString = ConfigurationManager.ConnectionStrings["Cabinet.Properties.Settings.cabinetConnectionString"].ConnectionString;

        internal static SqlConnection Connection
        {
            get
            {
                return new SqlConnection(connectionString);
            }
        }
    }
}




