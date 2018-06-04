using System;
using System.Collections.Generic;
using System.Text;

namespace monstruos.hl.compiler.common.Language
{
    public abstract class MetaObject
    {
        public enum MetaType
        {
            Interface,
            Class,
            Property,
            Method,
            Field,
            Struct,
            Enum
        }

        public string Name { get; set; }

        public abstract MetaType Type { get; }
    }
}
