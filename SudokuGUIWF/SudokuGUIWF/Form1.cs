using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SudokuGUIWF
{
    public partial class Form1 : Form
    {

        TextBox[,] aTB;
        TextBox testing;
        string path;
        public Form1()
        {
            InitializeComponent();
            testing = new TextBox();
            aTB = new TextBox[9, 9];
            int x = 30;
            int y = 30;
            for (int j = 0; j < 9; j++)
            {
                for (int i = 0; i < 9; i++)
                {
                    aTB[i, j] = new TextBox();
                    aTB[i, j].Width = 14;
                    aTB[i, j].MaxLength = 1;
                    aTB[i, j].Name = i + " " + j;
                    aTB[i, j].TextChanged += new EventHandler (TextBox_TextChanged);
                   // aTB[i, j].TextChanged += TextBox_TextChanged(aTB[i, j], null);
                    aTB[i, j].Location = new Point((x * i) + 10, (y * j) + 15);
                    this.Controls.Add(aTB[i, j]);

                }

            }
        }
                    

        private void Form1_Load(object sender, EventArgs e)
        {
            TextBox test = new TextBox();
           // test.Width = 14;
            //this.Controls.Add(test);


            testing.Location = new Point(0, 0);

           // this.Controls.Add(testing);
        }

        void TextBox_TextChanged(object sender, EventArgs e) 
        {
            TextBox test = (TextBox)sender;
            int[] re;
            re = getCoord(test.Name);
            testing.Text = (re[0] + " " + re[1]);
            if (!(re[0] == 8 && re[1] == 8) && !(test.Text == ""))
            {
                if (re[0] == 8)
                {
                    re[0] = -1;
                    re[1] += 1;
                }
                aTB[re[0] + 1, re[1]].Focus();
            }
        }

        int[] getCoord(String coords) 
        {
            int x = coords[0] - 48;
            int y = coords[coords.Length - 1] - 48;
            return new int [] {x,y};
        }

        private void button1_Click(object sender, EventArgs e)
        {

            OpenFileDialog file = new OpenFileDialog();
            if (file.ShowDialog() == DialogResult.OK)
            {
                path = file.FileName;
                //MessageBox.Show(path);
                Populate();
            }
        }
        private void Populate() 
        {
            string[] lines = System.IO.File.ReadAllLines(path);
            for (int i = 0; i < 9; i++)
            {
                string ass = lines[i];
               // MessageBox.Show(ass[0] + "ficks");
                for (int j = 0; j < 9; j++) 
                {
                    aTB[j, i].Text = ass[j]-48 + ""; 
                }
            }
                //Console.WriteLine("Press any key to exit.");
           // System.Console.ReadKey();
        
        }

        private void Start_Click(object sender, EventArgs e)
        {
            int[] arr1 = new int[9];
            unsafe 
            {
                fixed (int* parr1 = &arr1[0]) 
                {
                    SudokuWrapper.SudokuWrapperClass controlCpp =
                        new SudokuWrapper.SudokuWrapperClass();


                    for (int i = 0; i < 9; i++) 
                    {
                        initArr(arr1, i);
                        controlCpp.addRow(parr1, i);
                    }
                    if (controlCpp.process())
                    {
                        //MessageBox.Show("it works!");
                        int* ptr;
                        for (int i = 0; i < 9; i++) 
                        {
                            ptr = controlCpp.getGrid(i);
                            for (int j = 0; j < 9; j++) 
                            {
                                aTB[i, j].Text = ptr[j].ToString();
                            }
                        }




                        
                    }
                    else 
                    {
                        MessageBox.Show("Failure!");
                    }


                }
            
            }


        }
        void initArr(int[] arr, int index) 
        {
            for (int i = 0; i < 9; i++) 
            {
                if (aTB[index, i].Text == "") 
                {
                    arr[i] = 0;
                }
                else
                    arr[i] = aTB[index,i].Text[0] - 48;
            }
        
        }
    }
}
