using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using Cabinet.access;

namespace Cabinet.BusinessLogicLayer
{
    class InterventiiVechi_BL
    {
        interventiiVechi lista = new interventiiVechi();

        public DataSet Afisare_interventii(int idInterventie, DateTime data)
        {
            return lista.Afisare_interventii(idInterventie, data);           

        }
    }
}
