using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Globalization;
using System.Threading;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Threading;

namespace GameOfLifeWpfBoard
{
    public class DrawIt : FrameworkElement
    {
        VisualCollection visuals;
        private static List<Point> SelectedPoints = new List<Point>();
        private int yMax, xMax;
        private int BoxDimension = 500;
        private int scale = 20;

        public bool setNewBoundries(int value)
        {
            bool scaleChanged = false;

            double newScale = Math.Floor((double)500 / value);
            if ((int)newScale != scale)
            {
                scale = (int)newScale;
                xMax = BoxDimension / scale;
                yMax = xMax;
                scaleChanged = true;
            }

            return scaleChanged;
        }

        public DrawIt()
        {
            visuals = new VisualCollection(this);
            yMax = 25;
            xMax = 25;
            this.Loaded += new RoutedEventHandler(DrawIt_Loaded);
        }

        void DrawIt_Loaded(object sender, RoutedEventArgs e)
        {
            DrawBlankField();
        }

        public void DrawBlankField()
        {
            for (int y = 0; y < yMax; y++)
            {

                for (int x = 0; x < xMax; x++)
                {
                    DrawRect(Brushes.Aquamarine, x, y);
                }

            }
        }

        public void RedrawSelected()
        {
            SelectedPoints.ForEach(corr => DrawRect(Brushes.Aquamarine, (int)corr.X, (int)corr.Y));
        }

        private void FieldWasSelected(int x, int y)
        {
            Point selection = new Point(x, y);

            if (SelectedPoints.Contains(selection))
            {
                SelectedPoints.Remove(selection);
                DrawRect(Brushes.Aquamarine, x, y);
            }

            else
            {
                SelectedPoints.Add(selection);
                DrawRect(Brushes.Blue, x, y);
            }

        }

        public void DrawRectFromList(List<Point> points)
        {

            if (CollectionTooLarge()) Redraw();

            SelectedPoints = points;
            DrawBlankField();
            points.RemoveAll(corr => !(CoordinatesWithinBoundires((int)corr.X, (int)corr.Y)));
            points.ForEach(corr => DrawRect(Brushes.Blue, (int)corr.X, (int)corr.Y));
        }

        private void DrawRect(Brush brushColor, int x, int y)
        {

            DrawingVisual visual = new DrawingVisual();
            using (DrawingContext dc = visual.RenderOpen())
            {
                dc.DrawRectangle(brushColor, new Pen(Brushes.Black, 0.2),
                    new Rect(new Point(x * scale, y * scale), new Size(scale, scale)));
            }

            visuals.Add(visual);
        }

        protected override void OnMouseLeftButtonDown(MouseButtonEventArgs e)
        {
            base.OnMouseLeftButtonDown(e);

            Point pos = e.GetPosition(this);

            if (PointOutOfBoudnries(pos)) return;

            Point rounded = RoundUpCoordinates(pos);

            FieldWasSelected((int)rounded.X, (int)rounded.Y);
        }

        public bool PointOutOfBoudnries(Point pos)
        {
            return (pos.X > scale * xMax || pos.Y > scale * yMax);
        }

        public Point RoundUpCoordinates(Point input)
        {
            Point output = new Point();
            output.X = Math.Round(input.X) / scale;
            output.Y = Math.Round(input.Y) / scale;

            return output;
        }

        protected override Visual GetVisualChild(int index)
        {
            return visuals[index];
        }

        protected override int VisualChildrenCount
        {
            get
            {
                return visuals.Count;
            }
        }

        public static List<Point> getSelectedPoints()
        {
            return SelectedPoints;
        }

        public void clearSelectedPoints()
        {
            SelectedPoints.Clear();
        }

        public void ClearVisualsCollection()
        {
            visuals.Clear();
        }

        public void RedrawPanel()
        {
            ClearVisualsCollection();
            DrawBlankField();
        }

        public void Redraw()
        {
            ClearVisualsCollection();
            RedrawSelected();
        }

        public bool CollectionTooLarge()
        {
            return visuals.Count > 800;
        }

        public bool CoordinatesWithinBoundires(int x, int y)
        {
            if (x >= 0 && y >= 0)
            {
                return ((x * scale <= BoxDimension - scale) && (y * scale <= BoxDimension - scale));
            }

            return false;
        }
    }

}