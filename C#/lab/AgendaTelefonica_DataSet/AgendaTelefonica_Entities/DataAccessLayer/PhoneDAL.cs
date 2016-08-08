using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.SqlClient;
using System.Data;

namespace AgendaTelefonica_Entities.DataAccessLayer
{
    class PhoneDAL
    {
        DatabaseAccess da = new DatabaseAccess();
        public DataSet GetAllPhonesForPerson(int personID)
        {
            SqlParameter[] paramList = new SqlParameter[]
            {
                new SqlParameter("@personID", personID)
            };
            return da.ExecuteDataSet(DALHelper.Connection, "GetPhonesForPerson", paramList);
        }

        internal DataSet GetPhoneByID(int phoneID)
        {
            SqlParameter[] paramList = new SqlParameter[]
            {
                new SqlParameter("@phoneID", phoneID)
            };
            return da.ExecuteDataSet(DALHelper.Connection, "GetPhoneByID", paramList);
        }

        internal DataSet SavePhone(int phoneID, int personID, string phoneNumber, string description)
        {
            SqlParameter[] paramList = new SqlParameter[]
            {
                new SqlParameter("@phoneID", phoneID),
                new SqlParameter("@personID", personID),
                new SqlParameter("@phoneNumber", phoneNumber),
                new SqlParameter("@description", description)
            };
            return da.ExecuteDataSet(DALHelper.Connection, "SavePhone", paramList);
        }

        internal void DeletePhone(int phoneID)
        {
            SqlParameter[] paramList = new SqlParameter[]
            {
                new SqlParameter("@phoneID", phoneID)
            };
            da.ExecuteNonQuery(DALHelper.Connection, "DeletePhone", paramList);
        }
    }
}
