/* type comp;

[@bs.module] external rootComponent : SingleSpaReact.comp = "./Component.bs.js";


let footer = SingleSpaReact.config(rootComponent, "footer") */

type react;
type reactDOM;
type element;
type comp;
type bootstrap;
type mount;
type unmount;

[@bs.module] external component : comp = "./Component.bs.js";
[@bs.val][@bs.scope "document"] external getElementById : string => element = "getElementById";

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

let domElementGetter = () => getElementById("footer");
let opts = opts(
  ~react,
  ~reactDOM,
  ~rootComponent=component,
  ~domElementGetter=domElementGetter
);
let reactLifecycles = singleSpaReact(opts);

let bootstrap = [| reactLifecycles |. bootstrap |];
let mount = [| reactLifecycles |. mount |];
let unmount = [| reactLifecycles |. unmount |];
