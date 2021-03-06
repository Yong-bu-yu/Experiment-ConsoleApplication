using System;
using System.Windows.Forms;

namespace 实验窗体
{
    public partial class Form1 : Form
    {        
        public Form1()
        {
            InitializeComponent();
        }
        protected override void OnLoad(EventArgs e)
        {
            GetLanguages();
            SetNewCurrentLanguage();
        }

        public void GetLanguages()
        {
            //获得已经安装的语言列表
            foreach (InputLanguage lang in InputLanguage.InstalledInputLanguages)
            {
                textBox1.Text += lang.Culture.EnglishName + "\n";
            }
        }
        public void SetNewCurrentLanguage()
        {
            //获取默认的当前语言名称
            InputLanguage myDefaultLanguage = InputLanguage.DefaultInputLanguage;
            InputLanguage myCurrentLanguage = InputLanguage.CurrentInputLanguage;
            textBox1.Text = "Current inpu language is; " + myCurrentLanguage.Culture.EnglishName + "\n";
            textBox1.Text += "Default input language is: " + myDefaultLanguage.Culture.EnglishName + "\n";
            //把当前输入语言设置为默认语言，并显示当前语言名称
            InputLanguage.CurrentInputLanguage = myDefaultLanguage;
            textBox1.Text += "Current input language is now: " + myDefaultLanguage.Culture.EnglishName;
        }
    }
}
