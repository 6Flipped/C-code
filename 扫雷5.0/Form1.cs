using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 扫雷4._0
{
    public partial class Form1 : Form
    {

        SoundPlayer bgm1 = new SoundPlayer("1.wav");
        SoundPlayer bgm2 = new SoundPlayer("2.wav");
        //难度  1：简单9*9，2：中级16*16，3：高级16*30.
        private int costtime;//计时
        private int mineWidth = 30;//单个小按钮的边长
        private int xnum=9;//9列
        private int ynum=9;//9行
        private int minenum=10;//雷的个数。
        private int[,] flags;
        private int[,] MINES;
        private Button[,] minebtns;//定义雷的按钮

        public Form1()
        {
            InitializeComponent();
            button1.BackgroundImage = Image.FromFile("开始.png");
            labmine.Text = minenum.ToString();
            flags = new int[xnum, ynum];
            MINES = new int[xnum, ynum];
            minebtns = new Button[xnum, ynum];
            for (int x = 0; x < xnum; x++)
            {
                for (int y = 0; y < ynum; y++)
                {
                    minebtns[x, y] = new Button();
                    Controls.Add(minebtns[x, y]);
                    minebtns[x, y].Left = 50 + mineWidth * x;
                    minebtns[x, y].Location = new Point(10 + mineWidth * x, 80 + mineWidth * y);
                    minebtns[x, y].Width = mineWidth;
                    minebtns[x, y].Height = mineWidth;
                    minebtns[x, y].Name = "mines_" + x.ToString() + "_" + y.ToString();
                    minebtns[x, y].Visible = false;
                    minebtns[x, y].MouseUp += mineBtn_MouseUp;
                    minebtns[x, y].BackgroundImageLayout = ImageLayout.Stretch;
                    minebtns[x, y].BackgroundImage = Bitmap.FromFile("背景图.png");
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            bgm2.Stop();
            bgm1.Stop();
            button1.BackgroundImage = Image.FromFile("开始.png");
            GameInit();
            timer1.Start();
        }
        //游戏初始化
        private void GameInit()
        { 
            for (int x = 0; x < xnum; x++)
            {
                for (int y = 0; y < ynum; y++)
                {
                    minebtns[x, y].Text = " ";
                    minebtns[x, y].Visible = true;
                    minebtns[x, y].Enabled = true;
                    minebtns[x, y].BackgroundImage = Image.FromFile("背景图.png");//清空数字
                    MINES[x, y] = 0;//清空雷
                }
            }
            laymines();
        }

        private void laymines()
        {
            Random ra = new Random();
            int x, y;
            for (int i = 0; i < minenum;)
            {
                x = ra.Next(xnum);
                y = ra.Next(ynum);
                if (MINES[x, y] == 0)
                {
                    MINES[x, y] = 1;
                    i++;
                }
            }

        }
        //获取按钮周围雷的数目
        private int GetAroundMindCount(int x, int y)
        {
            int count = 0;
            int xmin = (x == 0) ? 0 : x - 1;
            int xmax = (x == xnum - 1) ? xnum - 1 : x + 1;
            int ymin = (y == 0) ? 0 : y - 1;
            int ymax = (y == ynum - 1) ? ynum - 1 : y + 1;
            for (int i = xmin; i <= xmax; i++)
            {
                for (int j = ymin; j <= ymax; j++)
                {
                    count += MINES[i, j];
                }
            }
            return count;

        }
        //对于周围雷数目为0的按钮展开，直到不为0或者到了边界为止
        private void ExpandMines(int x, int y)
        {

            int xmin = (x == 0) ? 0 : x - 1;
            int xmax = (x == xnum - 1) ? xnum - 1 : x + 1;
            int ymin = (y == 0) ? 0 : y - 1;
            int ymax = (y == ynum - 1) ? ynum - 1 : y + 1;
            for (int i = xmin; i <= xmax; i++)
            {
                for (int j = ymin; j <= ymax; j++)
                {
                    if (minebtns[i, j].Enabled == false)//避免出现死循环
                    {
                        continue;
                    }
                    int count = GetAroundMindCount(i, j);
                    if (count == 0)
                    {
                        minebtns[i, j].Enabled = false;//失效处理
                        minebtns[i, j].BackgroundImage = Image.FromFile("点开.png");
                        ExpandMines(i, j);
                    }
                    else
                    {
                        //minebtns[i, j].Text = count.ToString();
                        if (count == 1)
                            minebtns[i, j].BackgroundImage = Image.FromFile("1.gif");
                        if (count == 2)
                            minebtns[i, j].BackgroundImage = Image.FromFile("2.gif");
                        if (count == 3)
                            minebtns[i, j].BackgroundImage = Image.FromFile("3.gif");
                        minebtns[i, j].Enabled = false;
                    }
                }
            }
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            costtime++;
            labtime.Text = costtime.ToString();
        }
        //胜利判定
        private Boolean IsVictory()
        {
            for (int x = 0; x < xnum; x++)
            {
                for (int y = 0; y < ynum; y++)
                {
                    if (minebtns[x, y].Enabled && flags[x, y] != 1)
                        return false;
                    if (MINES[x, y] == 0 && flags[x, y] == 1)
                        return false;
                }
            }

            return true;
        }
        //踩雷后显示所有的区域
        private void showAll()
        {
            for (int x = 0; x < xnum; x++)
            {
                for (int y = 0; y < ynum; y++)
                {
                    int count = GetAroundMindCount(x, y);
                 
                    if (MINES[x, y] == 1)
                    {
                        minebtns[x, y].Text = "";
                        minebtns[x, y].BackgroundImage = Image.FromFile("地雷.gif");
                    }
                    minebtns[x, y].Enabled = false;
                    timer1.Stop();
                }
            }
        }
        private void labtime_Click(object sender, EventArgs e)
        {

        }


        /// <summary>
        ///  雷按钮事件
        /// </summary>
        /// <param name="sender">通过sender参数可以知道是哪个函数发出的事件</param>
        /// <param name="e">通过e参数可以知道是由左键还是右键单击的</param>
        private void mineBtn_MouseUp(object sender, MouseEventArgs e)
        {
            Button btn = (Button)sender;
            String[] str = btn.Name.Split('_');
            int x = int.Parse(str[1]);
            int y = Convert.ToInt16(str[2]);

            switch (e.Button)
            {
                case MouseButtons.Left:
                    if (flags[x, y] == 0)//如果有旗子则单击无效
                    {
                        if (MINES[x, y] == 1)//如果挖到雷
                        {
                            bgm2.Play();
                            showAll();
                            button1.BackgroundImage = Image.FromFile("输.png");
                            btn.BackgroundImage = Image.FromFile("爆炸地雷.gif");
                            MessageBox.Show("失败！！！", "结束");
                            timer1.Stop();
                        }
                        else//没挖到
                        {
                            btn.BackgroundImage = null;
                            int count = GetAroundMindCount(x, y);
                            if (count != 0)
                            {
                                //btn.Text = count.ToString();
                                if (count == 1)
                                    btn.BackgroundImage = Image.FromFile("1.gif");
                                if (count == 2)
                                    btn.BackgroundImage = Image.FromFile("2.gif");
                                if (count == 3)
                                    btn.BackgroundImage = Image.FromFile("3.gif");
                                if (count == 4)
                                    btn.BackgroundImage = Image.FromFile("4.gif");
                                if (count == 5)
                                    btn.BackgroundImage = Image.FromFile("5.gif");
                                if (count == 6)
                                    btn.BackgroundImage = Image.FromFile("6.gif"); 
                                if (count == 7)
                                    btn.BackgroundImage = Image.FromFile("7.gif");
                                if (count == 8)
                                    btn.BackgroundImage = Image.FromFile("8.gif");
                                btn.Enabled = false;
                            }
                            else
                            {
                                minebtns[x, y].BackgroundImage = Image.FromFile("点开.png");
                                ExpandMines(x, y);
                            }
                            //判定是否胜利
                            if (IsVictory())
                            {
                                button1.BackgroundImage = Image.FromFile("赢.png");
                                bgm1.Play();
                                flags[x, y] = 0;
                                timer1.Stop();
                                MessageBox.Show("胜利！！", "结束");
                            }
                        }
                    }
                    break;

                case MouseButtons.Right:
                    if (flags[x, y] == 1)
                    {
                        flags[x, y] = 0;
                        btn.BackgroundImage = null;
                        minenum++;
                    }
                    else
                    {
                        flags[x, y] = 1;
                        btn.BackgroundImage = Image.FromFile("小国旗.gif");
                        minenum--;
                    }
                    labmine.Text = minenum.ToString();
                    //判定是否胜利
                    if (IsVictory())
                    {
                        flags[x, y] = 0;
                        timer1.Stop();
                        MessageBox.Show("胜利！！", "结束");
                    }
                    break;
            }
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void labmine_Click(object sender, EventArgs e)
        {

        }
        private void 难度ToolStripMenuItem_Click(object sender, EventArgs e)
        {
           
        }

        private void 初级ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 form1 = new Form1();
            form1.Show();
        }

        private void 中级ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();
            form2.Show();
        }

        private void 高级ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form3 form3 = new Form3();
            form3.Show();
        }

        private void 帮助ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("先任意点开少量的方格，没有爆炸时，会出现一个数字，这个数字代表的意思是以它为中心的9个格子内所有雷的个数。一般围在一堆数字中间的有可能是雷，你在你认为是雷的那里右击，就可以把它设定为雷，然后在数字区用鼠标左右键双击，可以打开非雷区，等打开所有非雷区，你就赢啦！");
        }

        private void Form1_Load_1(object sender, EventArgs e)
        {

        }
    }
}
