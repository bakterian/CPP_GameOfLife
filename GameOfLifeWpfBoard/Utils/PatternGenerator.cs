using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ManagedGameOfLifeLib;
using System.Windows;
using System.Threading;

namespace GameOfLifeWpfBoard.Utils
{
    public class PatternGenerator
    {
        private List<LifeAddressM> simplePattern = new List<LifeAddressM>() 
        {  
            new LifeAddressM(12,12), 
            new LifeAddressM(12,13), 
            new LifeAddressM(13,13),
            new LifeAddressM(12,14)
        };

        private List<LifeAddressM> oscillator = new List<LifeAddressM>() 
        {  
            new LifeAddressM(12,12), 
            new LifeAddressM(12,13), 
            new LifeAddressM(12,14)
        };

        private List<LifeAddressM> brick = new List<LifeAddressM>() 
        {  
            new LifeAddressM(12,12), 
            new LifeAddressM(12,13), 
            new LifeAddressM(13,12),
            new LifeAddressM(13,13)
        };

        private List<LifeAddressM> Rpentomino = new List<LifeAddressM>() 
        {  
            new LifeAddressM(12,12), 
            new LifeAddressM(12,13), 
            new LifeAddressM(12,14),
            new LifeAddressM(13,12),
            new LifeAddressM(11,13)

        };

        public List<LifeAddressM> getPattern(PatternType patternType)
        {
            return PatternSwitch(patternType);
        }

        public List<Point> getPatternPoints(PatternType patternType)
        {
            return ListConverter(PatternSwitch(patternType));
        }


        public List<Point> ListConverter(List<LifeAddressM> entityList)
        {
            List<Point> Points = new List<Point>();

            entityList.ForEach(entity => Points.Add(new Point(entity.ixCoordinate, entity.iyCoordinate)));

            return Points;
        }

        private List<LifeAddressM> PatternSwitch(PatternType pattern)
        {
            switch (pattern)
            {
                case PatternType.Simple: return simplePattern;

                case PatternType.brick: return brick;

                case PatternType.oscillator: return oscillator;

                case PatternType.rPentomino: return Rpentomino;

                default: return simplePattern;
            }
        }
    }
}
