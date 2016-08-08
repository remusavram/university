using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgendaTelefonica_Entities.Entities;
using System.Data.SqlClient;

namespace AgendaTelefonica_Entities.DataAccessLayer
{
    class PhoneDAL
    {
        public List<Phone> GetAllPhonesForPerson(Person persoana)
        {
            SqlConnection connection = DALHelper.Connection;
            try
            {
                List<Phone> result = new List<Phone>();
                SqlCommand cmd = new SqlCommand("GetPhonesForPerson", connection);
                cmd.CommandType = System.Data.CommandType.StoredProcedure;
                SqlParameter paramIdPersoana = new SqlParameter("@personID", persoana.PersonID);
                cmd.Parameters.Add(paramIdPersoana);
                connection.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    result.Add(new Phone() { PhoneID = reader.GetInt32(0), PersonID = reader.GetInt32(1), PhoneNumber = reader.GetString(2), Description = reader.GetString(3) });
                }
                return result;
            }
            finally
            {
                connection.Close();
            }
        }

        internal void AddPhone(Phone telefon)
        {
            SqlConnection con = DALHelper.Connection;
            try
            {
                SqlCommand cmd = new SqlCommand("InsertPhone", con);
                cmd.CommandType = System.Data.CommandType.StoredProcedure;
                SqlParameter paramIdPersoana = new SqlParameter("@personID", telefon.PersonID);
                SqlParameter paramNumarTelefon = new SqlParameter("@phoneNumber", telefon.PhoneNumber);
                SqlParameter paramDescriere = new SqlParameter("@description", telefon.Description);
                SqlParameter paramIdTelefon = new SqlParameter("@phoneID", System.Data.SqlDbType.Int);
                paramIdTelefon.Direction = System.Data.ParameterDirection.Output;
                cmd.Parameters.Add(paramIdPersoana);
                cmd.Parameters.Add(paramIdTelefon);
                cmd.Parameters.Add(paramNumarTelefon);
                cmd.Parameters.Add(paramDescriere);
                con.Open();
                cmd.ExecuteNonQuery();
                if (!String.IsNullOrEmpty(paramIdTelefon.Value.ToString()))
                    telefon.PhoneID = (int?)paramIdTelefon.Value;
            }
            finally
            {
                con.Close();
            }
        }

        internal void DeletePhone(Phone telefon)
        {
            SqlConnection con = DALHelper.Connection;
            try
            {
                SqlCommand cmd = new SqlCommand("DeletePhone", con);
                cmd.CommandType = System.Data.CommandType.StoredProcedure;
                SqlParameter paramIdTelefon = new SqlParameter("@phoneID", telefon.PhoneID);
                cmd.Parameters.Add(paramIdTelefon);
                con.Open();
                cmd.ExecuteNonQuery();
            }
            finally
            {
                con.Close();
            }
        }
    }
}
