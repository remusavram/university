using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;

namespace Project_2___Pizza.DateAccesLayer
{
    class Tip_Pizza_Dal
    {
        DatabaseAccess da = new DatabaseAccess();
        public DataSet Afisare_Pizza()
        {
            return da.ExecuteDataSet(DALHelper.Connection, "Afisare_tip_pizza", null);
        }
    }
}
