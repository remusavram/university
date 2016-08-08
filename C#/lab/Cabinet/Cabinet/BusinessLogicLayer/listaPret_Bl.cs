using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using Cabinet.access;

namespace Cabinet.BusinessLogicLayer
{
    class listaPret_BL
    {
        listaPret lista = new listaPret();
        public DataSet DS_ListaPreturi()
        {
            return lista.AfisareListaPreturi();               

        }
    }
}
