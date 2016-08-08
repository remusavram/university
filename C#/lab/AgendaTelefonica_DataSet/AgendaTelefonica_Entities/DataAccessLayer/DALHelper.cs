using System;
using System.Collections.Generic;
//using System.Linq;
using System.Text;
using System.Configuration;
using System.Data.SqlClient;

namespace AgendaTelefonica_Entities.DataAccessLayer
{
    static class DALHelper
    {
        private static readonly String connectionString = ConfigurationManager.ConnectionStrings["myConStr"].ConnectionString;

        internal static SqlConnection Connection
        {
            get
            {
                return new SqlConnection(connectionString);
            }
        }
    }
}
