using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using Cabinet.access;

namespace Cabinet.BusinessLogicLayer
{
    class interventiiPacient_BL
    {
        interventiiPacient lista = new interventiiPacient();

        public DataSet Afisare_interventii_pacient(long idPacient)
        {
            return lista.InterventiiPacient(idPacient);           

        }
    }
}
