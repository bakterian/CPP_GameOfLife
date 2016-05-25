using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
using System.Web;
using System.Threading;
using GameOfLifeWpfBoard.Utils;
using ManagedGameOfLifeLib;

namespace GameOfLifeWpfBoard
{
    public partial class MainWindow : Window
    {       
        List<Point>             _PointsToDraw;
        speed                   _RenderSpeed;
        Thread                  _GameManagmentThread;
        BoardConfiguration      _BoardConfiguration;
        UserInfoCenterM         _UserGameInfoCenter;
        UserSteeringConsoleM    _UserSteeringConsole;
        PatternGenerator        _PatternGenerator = new PatternGenerator();

        public MainWindow()
        {
            InitializeComponent();
            InitComboBoxes();
            GrayPulsButtons();
            _BoardConfiguration = new BoardConfiguration(105, 25, 100);
            _RenderSpeed = speed.faster;
            _UserGameInfoCenter = new UserInfoCenterM();
            _UserSteeringConsole = new UserSteeringConsoleM();
        }

        private void GrayPulsButtons()
        {
            button7.IsEnabled = false;
            button8.IsEnabled = false;
        }

        private void InitComboBoxes()
        {
            comboBox1.Items.Add(new ComboboxItem("Ongoing", 0));
            comboBox1.Items.Add(new ComboboxItem("Step by step", 1));
            comboBox1.SelectedIndex = 0;

            comboBox2.Items.Add(new ComboboxItem("Slow", 3000));
            comboBox2.Items.Add(new ComboboxItem("Medium", 500));
            comboBox2.Items.Add(new ComboboxItem("Fast", 300));
            comboBox2.Items.Add(new ComboboxItem("Very Fast", 200));
            comboBox2.Items.Add(new ComboboxItem("Rapid", 50));
            comboBox2.SelectedIndex = 3;
        }     

        private void Start_Click(object sender, RoutedEventArgs e)
        {
            List<Point> selectedPoints = DrawIt.getSelectedPoints();
            selectedPoints.ForEach( point => _UserSteeringConsole.CreateLife( new LifeAddressM((int)point.X,(int)point.Y)));
            if (comboBox1.SelectedIndex == 0) 
            { 
                ContinuesExecution(); 
                return; 
            }
            OneCycleUp();
        }

        private void Stop_Click(object sender, RoutedEventArgs e)
        {
            if (_GameManagmentThread != null)
            {
                if (_GameManagmentThread.IsAlive)
                {
                    _GameManagmentThread.Abort();
                    _GameManagmentThread.Join();
                }
            }
        }

        private void ContinuesExecution()
        {
            AdjustSpeed();
            _GameManagmentThread = new Thread(new  ThreadStart(this.EndleesLoop));
            _GameManagmentThread.Start();
            while (!_GameManagmentThread.IsAlive);
            Thread.Sleep(1);
        }
        private void OneCycleUp()
        {
            _UserSteeringConsole.StartLifeCycle();
            drawIt.DrawRectFromList(_PatternGenerator.ListConverter(_UserGameInfoCenter.getPopulation()));
            GrayOutButtons(mode.StartCycle);
        }

        private void SimplePattern_Click(object sender, RoutedEventArgs e)
        {
            drawIt.DrawRectFromList(_PatternGenerator.getPatternPoints(PatternType.Simple));
        }

        private void BrickPattern_Click(object sender, RoutedEventArgs e)
        {
            drawIt.DrawRectFromList(_PatternGenerator.getPatternPoints(PatternType.brick));
        }

        private void OscillatorPatter_Click(object sender, RoutedEventArgs e)
        {
            drawIt.DrawRectFromList(_PatternGenerator.getPatternPoints(PatternType.oscillator));
        }

        private void Plus1Cycle_Click(object sender, RoutedEventArgs e)
        {
            _UserSteeringConsole.StartLifeCycle();
            drawIt.DrawRectFromList(_PatternGenerator.ListConverter(_UserGameInfoCenter.getPopulation()));
        }

        private void ClearButton_Click(object sender, RoutedEventArgs e)
        {
            drawIt.DrawBlankField();
            drawIt.clearSelectedPoints();
            _UserSteeringConsole.RemoveAllLife();
            drawIt.DrawRectFromList(_PatternGenerator.ListConverter(_UserGameInfoCenter.getPopulation()));
            GrayOutButtons(mode.StopCycle);
        }

        public void GrayOutButtons(mode CycleType)
        {
            bool boolVal = false;
            if (CycleType == mode.StartCycle) boolVal = true;

            button7.IsEnabled = boolVal;
            button8.IsEnabled = boolVal;
            button1.IsEnabled = !boolVal;

        }

        public void AdjustSpeed()
        {
            //comboBox2.SelectedValue
            ComboboxItem item = (ComboboxItem)comboBox2.SelectedItem;
            _RenderSpeed = (speed)item.getValue();
                
        }

        public void EndleesLoop()
        {
            while (true)
            {
                _UserSteeringConsole.StartLifeCycle();
                _PointsToDraw = _PatternGenerator.ListConverter(_UserGameInfoCenter.getPopulation());
                drawIt.Dispatcher.Invoke(DispatcherPriority.Render,
                new Action<List<Point>>(drawIt.DrawRectFromList),
                _PointsToDraw);
                Thread.Sleep((int)_RenderSpeed);
            }

        }

        private void comboBox2_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            AdjustSpeed();
        }

        private void Rpentomino_Click(object sender, RoutedEventArgs e)
        {
            drawIt.DrawRectFromList(_PatternGenerator.getPatternPoints(PatternType.rPentomino));
        }

        private void slBoardSize_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            double NewSize = Math.Floor((100 - slBoardSize.Value) * ((_BoardConfiguration.MaxBoundry - _BoardConfiguration.MinBoundry) / _BoardConfiguration.SliderMaxValue) + _BoardConfiguration.MinBoundry);

            if (drawIt != null)
            {
                if (drawIt.setNewBoundries((int)NewSize))
                {
                    drawIt.RedrawPanel();
                }
            }
        }

        private void Grid_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            List<Point> selectedPoints = DrawIt.getSelectedPoints();
            int last_addedPoint = selectedPoints.Count - 1 ;
            int x = (int)selectedPoints[last_addedPoint].X;
            int y = (int)selectedPoints[last_addedPoint].Y;
            _UserSteeringConsole.CreateLife( new LifeAddressM(x, y));
        }
    }
}