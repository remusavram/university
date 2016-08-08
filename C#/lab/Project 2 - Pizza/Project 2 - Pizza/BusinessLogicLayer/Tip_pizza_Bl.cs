using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using Project_2___Pizza.DateAccesLayer;

namespace Project_2___Pizza.BusinessLogicLayer
{
    class Tip_pizza_Bl
    {
        Tip_Pizza_Dal tip = new Tip_Pizza_Dal();
        public DataSet Afisare_Pizza()
        {
            return tip.Afisare_Pizza();
        }
    }
}
