using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using AgendaTelefonica_Entities.Entities;
using System.Data.SqlClient;

namespace AgendaTelefonica_Entities.DataAccessLayer
{
    class PersonDAL
    {
        public List<Person> GetAllPersons()
        {
            SqlConnection con = DALHelper.Connection;
            try
            {
                SqlCommand cmd = new SqlCommand("GetAllPersons", con);
                List<Person> result = new List<Person>();
                cmd.CommandType = System.Data.CommandType.StoredProcedure;
                con.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    result.Add(new Person() { PersonID = (int)( reader[0] ), Address=reader.IsDBNull(2) ? null : reader[2].ToString(), Name=reader.GetString(1)});
                }
                reader.Close();
                return result;
            }
            finally
            {
                con.Close();
            }
        }

        internal List<Person> GetAllPersonsWithNoPhone()
        {
            SqlConnection con = DALHelper.Connection;
            try
            {
                SqlCommand cmd = new SqlCommand("GetPersonsWithNoPhone", con);
                List<Person> result = new List<Person>();
                cmd.CommandType = System.Data.CommandType.StoredProcedure;
                con.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    result.Add(new Person() { PersonID = (int)(reader["PersonID"]), Address = reader["Address"].ToString(), Name = reader["Name"].ToString() });
                }
                reader.Close();
                return result;
            }
            finally
            {
                con.Close();
            }
        }

        internal void AddPerson(Person persoana)
        {
            SqlConnection con = DALHelper.Connection;
            try
            {
                SqlCommand cmd = new SqlCommand("InsertPerson", con);
                cmd.CommandType = System.Data.CommandType.StoredProcedure;
                SqlParameter paramNume = new SqlParameter("@name", persoana.Name);
                SqlParameter paramAdresa;
                if (String.IsNullOrEmpty(persoana.Address))
                {
                    paramAdresa = new SqlParameter("@address", DBNull.Value);
                }
                else
                {
                    paramAdresa = new SqlParameter("@address", persoana.Address);
                }
                SqlParameter paramIdPersoana = new SqlParameter("@personID", System.Data.SqlDbType.Int);
                paramIdPersoana.Direction = System.Data.ParameterDirection.Output;
                cmd.Parameters.Add(paramNume);
                cmd.Parameters.Add(paramAdresa);
                cmd.Parameters.Add(paramIdPersoana);
                con.Open();
                cmd.ExecuteNonQuery();
                persoana.PersonID = (int)paramIdPersoana.Value;
            }
            finally
            {
                con.Close();
            }
        }

        internal void DeletePerson(Person persoana)
        {
            SqlConnection con = DALHelper.Connection;
            try
            {
                SqlCommand cmd = new SqlCommand("DeletePerson", con);
                cmd.CommandType = System.Data.CommandType.StoredProcedure;
                SqlParameter paramIdPersoana = new SqlParameter("@personID", persoana.PersonID);
                cmd.Parameters.Add(paramIdPersoana);
                con.Open();
                cmd.ExecuteNonQuery();
            }
            finally
            {
                con.Close();
            }
        }

        internal void ModifyPerson(Person persoana)
        {
            SqlConnection con = DALHelper.Connection;
            try
            {
                SqlCommand cmd = new SqlCommand("UpdatePerson", con);
                cmd.CommandType = System.Data.CommandType.StoredProcedure;
                SqlParameter paramIdPersoana = new SqlParameter("@personID", persoana.PersonID);
                SqlParameter paramNume = new SqlParameter("@name", persoana.Name);
                SqlParameter paramAdresa = new SqlParameter();
                paramAdresa.ParameterName = "@address";
                if (String.IsNullOrEmpty(persoana.Address))
                {
                    paramAdresa.Value = DBNull.Value;
                }
                else
                {
                    paramAdresa.Value = persoana.Address;
                }
                cmd.Parameters.Add(paramIdPersoana);
                cmd.Parameters.Add(paramNume);
                cmd.Parameters.Add(paramAdresa);
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
