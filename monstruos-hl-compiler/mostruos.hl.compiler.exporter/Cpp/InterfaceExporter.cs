using monstruos.hl.compiler.common.Language;
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;

namespace monstruos.hl.compiler.exporter.Cpp
{
    public class InterfaceExporter
    {
        public string Export(Interface interf)
        {
            var sb = new StringBuilder();

            if(interf.IsGeneric)
            {
                sb.Append("template <");
                sb.Append(string.Join(", ", interf.Generics.Select(GenericToString)));
                sb.AppendLine(">");
            }

            sb.AppendFormat("class {0}", interf.Name);

            if(interf.Implements.Count > 0)
            {
                sb.Append(": ");
                sb.Append(string.Join(", ", interf.Implements.Select(Implement)));
            }

            sb.AppendLine("{");
            sb.AppendLine("};");

            return sb.ToString();
        }

        private string Implement(Interface interf)
        {
            if (interf.IsGeneric)
            {
                throw new NotImplementedException();
            }

            return "public virtual " + interf.Name;
        }

        private string GenericToString(GenericDefinition generic)
        {
            return "class " + generic.Name;
        }
    }
}
