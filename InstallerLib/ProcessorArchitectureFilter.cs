using System;

namespace InstallerLib
{
    public class ProcessorArchitectureFilter : XmlFilter
    {
        private string[] _processorArchitectureFilters;

        public ProcessorArchitectureFilter(string processorArchitectureFilter)
        {
            if (processorArchitectureFilter.Length > 0)
            {
                _processorArchitectureFilters = processorArchitectureFilter.Split(",".ToCharArray());
            }
        }

        private bool IsSupported(string filter)
        {
            // no filters here, included since no filter
            if (_processorArchitectureFilters == null || _processorArchitectureFilters.Length == 0)
                return true;

            // no filter in the target, included in all configurations
            if (string.IsNullOrEmpty(filter))
                return true;

            string[] filters = filter.Split(",".ToCharArray());
            foreach (string left in _processorArchitectureFilters)
            {
                // tolerate blanks
                if (string.IsNullOrEmpty(left))
                    continue;

                // don't support ! in front of PA
                if (left[0] == '!')
                {
                    throw new Exception("Processor architecture filter doesn't support ! operator.");
                }

                foreach (string r in filters)
                {
                    string right = r;
                    if (string.IsNullOrEmpty(right))
                        continue;

                    // support ! in front of PA
                    bool right_not = false;
                    if (right[0] == '!')
                    {
                        right_not = true;
                        right = right.Remove(0, 1);
                    }

                    if (right_not && left == right)
                        return false;
                    else if (!right_not && left == right)
                        return true;
                }
            }

            return false;
        }

        public bool IsSupported(XmlClass clazz)
        {
            if (clazz is Configuration)
            {
                Configuration configuration = clazz as Configuration;
                return IsSupported(configuration.processor_architecture_filter);
            }
            else if (clazz is Component)
            {
                Component component = clazz as Component;
                return IsSupported(component.processor_architecture_filter);
            }

            return true;
        }
    }
}
