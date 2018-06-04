using System;
using System.Collections.Generic;
using System.Text;

namespace monstruos.hl.compiler.common.Language
{
    public abstract class MetaObjectWithGenerics : MetaObject
    {
        public List<GenericDefinition> Generics { get; private set; }

        public bool IsGeneric
        {
            get
            {
                return Generics.Count > 0;
            }
        }

        public MetaObjectWithGenerics()
        {
            Generics = new List<GenericDefinition>();
        }
    }
}
