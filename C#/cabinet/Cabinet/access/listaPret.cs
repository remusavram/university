using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using Cabinet.access;

namespace Cabinet.access
{
    class listaPret
    {
        dbAccess dal = new dbAccess();
        public DataSet AfisareListaPreturi()
        {
            return dal.ExecuteDataSet(DALHelper.Connection, "afisareListaPret",null);
        }

    }
}
