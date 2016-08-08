using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.SqlClient;

namespace Cabinet.access
{
    class dbAccess
    {
     public String ExecuteNonQuery(SqlConnection conn, String storedProcedureName, SqlParameter[] paramsList)
        {
            //SqlConnection conn = new SqlConnection(connectionString);
            try
            {
                SqlCommand cmd = new SqlCommand(storedProcedureName, conn);
                cmd.CommandType = System.Data.CommandType.StoredProcedure;
                if (paramsList != null)
                {
                    foreach (SqlParameter param in paramsList)
                    {
                        cmd.Parameters.Add(param);
                    }
                }
                conn.Open();
                //cmd.ExecuteNonQuery();
                return cmd.ExecuteNonQuery().ToString();
            }
            finally
            {
                conn.Close();
            }
        }

       
        public DataSet ExecuteDataSet(SqlConnection conn, String storedProcedureName, SqlParameter[] paramsList)
        {
            //SqlConnection conn = new SqlConnection(connectionString);
            DataSet result = new DataSet();
            try
            {
                SqlCommand cmd = new SqlCommand(storedProcedureName, conn);
                cmd.CommandType = CommandType.StoredProcedure;
                if (paramsList != null)
                {
                    foreach (SqlParameter param in paramsList)
                    {
                        cmd.Parameters.Add(param);
                    }
                }
                conn.Open();
                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                adapter.Fill(result);
                adapter.Dispose();
            }
            finally
            {
                conn.Close();
            }
            return result;
        }
    }
}


