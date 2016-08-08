using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AgendaTelefonica_Entities.Exceptions
{
    public class AgendaException : ApplicationException
    {
        public AgendaException(String message)
            : base(message)
        {

        }
    }
}
