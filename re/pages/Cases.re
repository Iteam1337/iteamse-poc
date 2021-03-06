module Style = {
  open Css;

  let cardBorder =
    style([
      borderLeftWidth(`zero),
      borderLeftStyle(`solid),
      paddingLeft(`zero),
      transitionProperty("border-left-width, padding-left"),
      transitionDuration(200),
      transitionTimingFunction(`easeInOut),
    ]);

  let cardText = merge(["border-aquamarine mt-4", cardBorder]);

  let cardImage =
    style([
      media(
        Theme.Breakpoints.fromType(`Mobile),
        [important(width(pct(100.0))), important(height(px(320)))],
      ),
    ]);

  let card =
    merge([
      "cursor-pointer",
      style([
        hover([
          selector(
            "." ++ cardBorder,
            [borderLeftWidth(`px(10)), paddingLeft(`px(10))],
          ),
        ]),
      ]),
    ]);
};

[@react.component]
let make = (~data, ~projects) => {
  let {header}: Page.Cases.t = Page.Cases.make(data);

  <>
    <Block.Header
      backgroundImage={header.url}
      backgroundFluid={header.localFile}
      color={header.textBgColor}
      messageOne={header.text}
      messageTwo={header.textSecond}
    />
    <Block.Section color=`White>
      <div className="grid md:grid-columns-2 grid-gap-8">
        {projects
         ->Belt.List.fromArray
         ->Belt.List.mapReverse(project => {
             let projectTitle = project##title;

             <Gatsby.Link
               ariaLabel={j|Gå till projekt-sidan för $projectTitle|j}
               key=project##slug
               className={Some(Style.card)}
               _to={"/case/" ++ project##slug}>
               <div
                 className="flex items-center justify-center bg-concrete-dark p-8 tablet:p-2 tablet-landscape:p-2">
                 <Gatsby.FixedImg
                   className={Some(Style.cardImage)}
                   fixed=project##thumbnailImage##fixed
                 />
               </div>
               <div className=Style.cardText>
                 <div className="text-lg font-medium">
                   {React.string(project##title)}
                 </div>
                 <div className="text-2xl font-light mt-1">
                   {React.string(project##shortDescription)}
                 </div>
               </div>
             </Gatsby.Link>;
           })
         ->Belt.List.toArray
         ->React.array}
      </div>
    </Block.Section>
  </>;
};

let default = make;
