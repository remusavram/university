using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using Cabinet.access;

namespace Cabinet.BusinessLogicLayer
{
    class listaPacientiSortataDupaNrInterventii_BL
    {
        listaPacientilorSortataDupaNrInterventii lista = new listaPacientilorSortataDupaNrInterventii();

        public DataSet listaPacienti_SortataDupaNrInterventii(int idMedic)
        {
            return lista.listaPacientiSortataDupaNrInterventii(idMedic);          

        }
    }
}
