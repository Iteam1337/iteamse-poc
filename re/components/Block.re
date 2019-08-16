module Markdown = {
  module ReactMarkdown = {
    [@bs.module] [@react.component]
    external make: (~source: string, ~className: string) => React.element =
      "react-markdown";
  };

  [@react.component]
  let make = (~source) => <ReactMarkdown source className="markdown" />;
};

module Header = {
  let bgImage = imageUrl => Css.(style([backgroundImage(`url(imageUrl))]));

  [@react.component]
  let make =
      (
        ~backgroundImage as bg,
        ~color as c,
        ~messageOne,
        ~messageTwo=None,
        ~messageTwoLight=false,
      ) => {
    let marker = Css.merge(["px-2 py-1", Theme.Colors.fromType(c)]);
    let navigationBackground =
      Css.(
        merge([
          style([
            backgroundImage(
              linearGradient(
                `deg(180.0),
                [
                  (`px(0), `rgba((0, 0, 0, 0.3))),
                  (`px(100), `rgba((0, 0, 0, 0.0))),
                ],
              ),
            ),
          ]),
          "grid md:grid-columns-1024 col-bleed",
        ])
      );

    <header
      className={Css.merge([
        "grid md:grid-columns-1024 grid-columns-1fr bg-top bg-cover md:h-jumbo h-md",
        bgImage(bg),
      ])}>
      <div className=navigationBackground>
        <Navigation />
        <div
          className="md:col-start-2 self-end md:pb-20 pb-8
        tablet-landscape:px-5">
          <Typography.H1 className="ml-5 md:ml-0">
            <span className=marker> messageOne->React.string </span>
            {messageTwo
             ->Belt.Option.map(m =>
                 <>
                   <div className="mt-1" />
                   <span
                     className={Css.merge([
                       marker,
                       "font-light"->Cn.ifTrue(messageTwoLight),
                     ])}>
                     m->React.string
                   </span>
                 </>
               )
             ->Belt.Option.getWithDefault(React.null)}
          </Typography.H1>
        </div>
      </div>
    </header>;
  };
};

module StartpageHeader = {
  let bgImage = imageUrl => Css.(style([backgroundImage(`url(imageUrl))]));

  [@react.component]
  let make = (~title, ~lead, ~illustrationIteamI, ~backgroundImage as bg) => {
    <header
      className=Css.(
        merge([
          "grid lg:grid-columns-1024 tablet:px-4 grid-columns-1fr bg-no-repeat md:h-startpage2019 h-md",
          style([backgroundPosition(pct(70.), pct(120.))]),
          bgImage(bg),
        ])
      )>
      <div className="grid lg:grid-columns-1024 col-bleed">
        <Navigation color=`Black />
        <div
          className="md:col-start-2 self-end md:pb-20 pb-8 startpage2019 flex mobile:flex-col-reverse
          lg:flex-row tablet-landscape:px-5">
          <div className="flex items-start justify-center flex-col">
            <h1 className="md:text-3xl font-light text-3xl mb-12">
              title->React.string
            </h1>
            <Markdown source=lead />
          </div>
          <img
            src=illustrationIteamI
            className="tablet:w-48 tablet:p-4"
            alt="The I in Iteam as a construction-site illustration"
          />
        </div>
      </div>
    </header>;
  };
};

module Text = {
  [@react.component]
  let make = (~title, ~children as source, ~subtitle=?) => {
    <section
      className="grid-gap-2-y grid md:grid-columns-12 col-start-2
      col-end-2 grid-gap-8-x tablet-landscape:px-5">
      <div className="md:col-start-1 md:col-end-5">
        <Typography.H2> title </Typography.H2>
        {subtitle
         ->Belt.Option.map(s =>
             <span className="text-lg"> s->React.string </span>
           )
         ->Belt.Option.getWithDefault(React.null)}
      </div>
      <div className="md:col-start-5 md:col-end-13"> <Markdown source /> </div>
    </section>;
  };
};

module Element = {
  [@react.component]
  let make = (~title, ~children, ~subtitle=?) => {
    <section
      className="grid-gap-2-y grid md:grid-columns-12 col-start-2
      col-end-2 grid-gap-8-x tablet-landscape:px-5">
      <div className="md:col-start-1 md:col-end-5">
        <Typography.H2> title </Typography.H2>
        {subtitle
         ->Belt.Option.map(s =>
             <span className="text-lg"> s->React.string </span>
           )
         ->Belt.Option.getWithDefault(React.null)}
      </div>
      <div className="md:col-start-5 md:col-end-13"> children </div>
    </section>;
  };
};

module Illustration = {
  [@react.component]
  let make = (~src) => {
    <div
      className="flex justify-center md:grid grid-columns-12 col-start-2 col-end-2">
      <img className="max-w-xs col-start-6 md:max-w-initial" src alt="" />
    </div>;
  };
};

module Section = {
  [@react.component]
  let make = (~color as c, ~children) => {
    <div
      className={Css.merge([
        "grid-columns-1fr grid py-10 md:py-24 md:grid-columns-1024 col-bleed",
        Theme.Colors.fromType(c),
      ])}>
      children
    </div>;
  };
};

module CTA = {
  [@react.component]
  let make = (~button, ~title, ~children, ~illustration) => {
    <div
      className="grid-gap-2-y grid md:grid-columns-12 col-start-2 col-end-2
      tablet-landscape:px-5">
      <div className="md:col-start-1 md:col-end-5">
        <img src=illustration alt="" />
      </div>
      <div className="md:col-start-5 md:col-end-13">
        <Typography.H2> title </Typography.H2>
        <p className="pt-2 pb-10"> children->React.string </p>
        <Button.Secondary href="mailto:info@iteam.se">
          button
        </Button.Secondary>
      </div>
    </div>;
  };
};

module Image = {
  [@react.component]
  let make = (~src) => {
    <img className="col-bleed w-full" src alt="" />;
  };
};
