using System.Drawing;

namespace InstallerLib
{
    /// <summary>
    /// A rectangle represented in xml
    /// </summary>
    public static class XmlRectangle
    {
        public static Rectangle FromString(string s)
        {
            if (string.IsNullOrEmpty(s))
                return new Rectangle();

            string[] parts = s.Split(",".ToCharArray(), 4);
            if (parts.Length != 4)
                return new Rectangle();

            return new Rectangle(
                int.Parse(parts[0]),
                int.Parse(parts[1]),
                int.Parse(parts[2]),
                int.Parse(parts[3]));
        }

        public static string ToString(Rectangle r)
        {
            if (r.X == 0 && r.Y == 0 && r.Left == 0 && r.Right == 0 && r.Top == 0 && r.Bottom == 0)
                return string.Empty;

            return string.Format("{0},{1},{2},{3}", r.Left, r.Top, r.Width, r.Height);
        }
    }
}
