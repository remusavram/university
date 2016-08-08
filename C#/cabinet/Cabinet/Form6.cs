using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Cabinet.BusinessLogicLayer;

namespace Cabinet
{
    public partial class Form6 : Form
    {
        public Form6()
        {
            InitializeComponent();
        }

        private void Form6_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'cabinetDataSet3.programari' table. You can move, or remove it, as needed.
            this.programariTableAdapter.Fill(this.cabinetDataSet3.programari);
            // TODO: This line of code loads data into the 'cabinetDataSet3.medici' table. You can move, or remove it, as needed.
            this.mediciTableAdapter.Fill(this.cabinetDataSet3.medici);

        }

        public static int GetWeeks(DateTime stdate, DateTime eddate)
        {

            TimeSpan t = eddate - stdate;
            int iDays;

            if (t.Days < 7)
            {
                if (stdate.DayOfWeek > eddate.DayOfWeek)
                    return 1; //It is accross the week 

                else
                    return 0; // same week
            }
            else
            {
                iDays = t.Days - 7 + (int)stdate.DayOfWeek;
                int i = 0;
                int k = 0;

                for (i = 1; k < iDays; i++)
                {
                    k += 7;
                }

                if (i > 1 && eddate.DayOfWeek != DayOfWeek.Sunday) i -= 1;
                return i;
            }
        }




        public static double CalculateBDay(
            DateTime startDate,
            DateTime endDate,
            int NoOfDayWeek /* No of Working Day per week - 5*/
           )
        {

            /// <summary>
            /// Calulates Business Days within the given range of days.
            /// Start date and End date inclusive.
            /// </summary>
            /// <param name="startDate">Datetime object 
            /// containing Starting Date</param>
            /// <param name="endDate">Datetime object containing 
            /// End Date</param>
            /// <param name="NoOfDayWeek">integer denoting No of Business 
            /// Day in a week</param>
            /// <param name="DayType"> DayType=0 for Business Day and 
            /// DayType=1 for WeekEnds </param>
            /// <returns></returns>

            double iWeek, iDays, isDays, ieDays;
            //* Find the number of weeks between the dates. Subtract 1 */
            // since we do not want to count the current week. * /
            iWeek = (double)GetWeeks(startDate, endDate) -1;
            iDays = iWeek * NoOfDayWeek;
            //
            if (NoOfDayWeek == 5)
            {
                //-- If Saturday, Sunday is holiday
                if (startDate.DayOfWeek == DayOfWeek.Saturday)
                    isDays = 7 - (int)startDate.DayOfWeek;
                else
                    isDays = 7 - (int)startDate.DayOfWeek - 1;
            }
            else
            {
                //-- If Sunday is only <st1:place>Holiday</st1:place>
                isDays = 7 - (int)startDate.DayOfWeek;
            }
            //-- Calculate the days in the last week. These are not included in the
            //-- week calculation. Since we are starting with the end date, we only
            //-- remove the Sunday (datepart=1) from the number of days. If the end
            //-- date is Saturday, correct for this.
            if (NoOfDayWeek == 5)
            {
                if (endDate.DayOfWeek == DayOfWeek.Saturday)
                    ieDays = (int)endDate.DayOfWeek - 2;
                else
                    ieDays = (int)endDate.DayOfWeek - 1;
            }
            else
            {
                ieDays = (int)endDate.DayOfWeek - 1;
            }
            //-- Sum everything together.
            iDays = iDays + isDays + ieDays;
            if ((startDate.DayOfWeek != DayOfWeek.Saturday) && (startDate.DayOfWeek != DayOfWeek.Sunday))
            { iDays = iDays + 1; }

                return iDays;

        }


        private void button1_Click(object sender, EventArgs e)
        {
            double durataProgramari = 0;
            DateTime dataStart= Convert.ToDateTime(monthCalendar1.SelectionRange.Start);
            DateTime dataEnd = Convert.ToDateTime(monthCalendar2.SelectionRange.Start);
            int idMedic = Convert.ToInt32(comboMedici.SelectedValue);
            if (dataEnd < dataStart)
            { MessageBox.Show("Intervalul selectat nu e valid!"); }
            else
            {
                double nrZile = CalculateBDay(dataStart, dataEnd, 5);
                gradOcupare_BL gradOcupare = new gradOcupare_BL();
                DataSet Durata = gradOcupare.castig_Medic(idMedic, dataStart, dataEnd);

                //float valoare = Durata.Tables[0].Rows
                // MessageBox.Show(Convert.ToString(Durata.Tables[0].Rows.Count));
                if (Durata.Tables[0].Rows.Count > 0)
                    foreach (DataRow row in Durata.Tables[0].Rows)
                    {
                        foreach (DataColumn col in Durata.Tables[0].Columns)
                        {
                            if (!(Convert.ToString(row[col]) == ""))
                                //MessageBox.Show(Convert.ToString(row[col]));
                                durataProgramari = Convert.ToDouble(row[col]);

                        }
                    }

                double zileLucratoare = CalculateBDay(dataStart, dataEnd, 5);
                double gradOcu = Math.Round((100 * durataProgramari) / (zileLucratoare * 8), 2);
                label4.Text = "Durata interventii     " + Convert.ToString(durataProgramari) + "  ore";
                label5.Text = "Numar zile lucratoare     " + Convert.ToString(zileLucratoare);
                label6.Text = "Grad de ocupare     " + Convert.ToString(gradOcu) + "%";
                //MessageBox.Show(Convert.ToString(gradOcu));
                //label1.Text = label1.Text + " "+Convert.ToString(valoare); }
            }

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}
