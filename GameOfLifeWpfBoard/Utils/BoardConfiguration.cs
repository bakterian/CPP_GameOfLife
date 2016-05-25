using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameOfLifeWpfBoard.Utils
{
    class BoardConfiguration
    {
        public BoardConfiguration(int maxBoundry, int minBoundry, int sliderMaxValue)
        {
            MaxBoundry = maxBoundry;
            MinBoundry = minBoundry;
            SliderMaxValue = sliderMaxValue;
        }

        public int MaxBoundry { get; set; }

        public int MinBoundry { get; set; }

        public double SliderMaxValue { get; set; }
    }
}
