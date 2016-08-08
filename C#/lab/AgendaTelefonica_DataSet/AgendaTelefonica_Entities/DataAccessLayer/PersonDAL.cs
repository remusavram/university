using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.SqlClient;
using System.Data;

namespace AgendaTelefonica_Entities.DataAccessLayer
{
    public class PersonDAL
    {
        DatabaseAccess da = new DatabaseAccess();
        public DataSet GetAllPersons()
        {
            return da.ExecuteDataSet(DALHelper.Connection, "GetAllPersons", null);
        }

        internal DataSet GetAllPersonsWithNoPhone()
        {
            return da.ExecuteDataSet(DALHelper.Connection, "GetPersonsWithNoPhone", null);
        }
        internal DataSet GetPersonByID(int personID)
        {
            SqlParameter[] paramList = new SqlParameter[]
            {
                new SqlParameter("@personID", personID)
            };
            return da.ExecuteDataSet(DALHelper.Connection, "GetPersonByID", paramList);
        }
        internal DataSet SavePerson(int personID, string name, string address)
        {
            SqlParameter[] paramList = new SqlParameter[]
            {
                new SqlParameter("@personID", personID),
                new SqlParameter("@name", name),
                new SqlParameter("@address", address)
            };
            return da.ExecuteDataSet(DALHelper.Connection, "SavePerson", paramList);
        }

        internal void DeletePerson(int personID)
        {
            SqlParameter[] paramList = new SqlParameter[]
            {
                new SqlParameter("@personID", personID)
            };
            da.ExecuteNonQuery(DALHelper.Connection, "DeletePerson", paramList);
        }
    }
}
