let component = ReasonReact.statelessComponent("Component");

let handleClick = (_event, _self) => Js.log("clicked!");

let make =  _children => {
  ...component,
  render: self =>
    <div onClick=(self.handle(handleClick))>
      (ReasonReact.string("footer"))
    </div>,
};
