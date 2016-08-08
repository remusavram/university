using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AgendaTelefonica_Entities.Entities
{
    class Phone
    {
        public int? PhoneID { get; set; }
        public int? PersonID { get; set; }
        public String PhoneNumber { get; set; }
        public String Description { get; set; }

        public String PhoneNumberAndDescription
        {
            get
            {
                return PhoneNumber + " " + Description;
            }
        }
    }
}
