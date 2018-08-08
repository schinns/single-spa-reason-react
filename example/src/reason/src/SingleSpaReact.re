type react;
type reactDOM;
type element;
type comp;
type bootstrap;
type mount;
type unmount;

[@bs.val][@bs.scope "document"]
external getElementById : string => element = "getElementById";

[@bs.deriving abstract]
type opts = {
  [@bs.as "React"] react: react,
  [@bs.as "ReactDOM"] reactDOM: reactDOM,
  rootComponent: comp,
  domElementGetter: element
};

[@bs.deriving abstract]
type lifecycles = {
  bootstrap,
  mount,
  unmount
};

[@bs.module] external react : react = "react";
[@bs.module] external reactDOM : reactDOM = "react-dom";
[@bs.module "single-spa-react"] external singleSpaReact : opts => lifecycles = "default";

let config = (comp, elementName) => {
  let domElementGetter = () => getElementById(elementName);
  let opts = opts(
    ~react,
    ~reactDOM,
    ~rootComponent=comp,
    ~domElementGetter=domElementGetter()
  );
  singleSpaReact(opts);
}
