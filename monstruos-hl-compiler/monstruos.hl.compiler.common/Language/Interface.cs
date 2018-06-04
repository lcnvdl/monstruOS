using System;
using System.Collections.Generic;

namespace monstruos.hl.compiler.common.Language
{
    public class Interface : MetaObjectWithGenerics
    {
        public override MetaType Type => MetaType.Interface;

        public List<Interface> Implements { get; private set; }

        public Interface()
        {
            Implements = new List<Interface>();
        }

    }
}
