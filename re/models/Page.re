module Employee = {
  type t = {
    avatar: option(string),
    email: string,
    name: string,
    short: string,
    title: string,
  };

  let make = employee => {
    avatar: {
      switch (employee##avatar->Js.Nullable.toOption) {
      | None => None
      | Some(src) => Some(src##file##url)
      };
    },
    email: employee##email,
    name: employee##name,
    short: employee##short,
    title: employee##title,
  };

  let fromArray = employees =>
    employees->Belt.Array.map(make)->Belt.List.fromArray;
};

module Start = {
  type t = {
    ctaTitle: string,
    ctaButton: string,
    ctaText: string,
    weAreTitle: string,
    weAreText: string,
    weOfferTitle: string,
    weOfferText: string,
    ourMethodTitle: string,
    ourMethodText: string,
    contacts: list(Employee.t),
  };

  let make = page => {
    ctaTitle: page##ctaTitle,
    ctaText: page##ctaText##ctaText,
    ctaButton: page##ctaButtonText,
    weAreTitle: page##weAreTitle,
    weAreText: page##weAreText##weAreText,
    weOfferTitle: page##weOfferTitle,
    weOfferText: page##weOfferText##weOfferText,
    ourMethodTitle: page##ourMethodTitle,
    ourMethodText: page##ourMethodText##ourMethodText,
    contacts: Employee.fromArray(page##contacts),
  };
};

module About = {
  type t = {
    headerText1: string,
    headerText2: string,
    headerBgColor: string,
    funTitle: string,
    funText: string,
    goodText: string,
    goodTitle: string,
    headerImage: string,
    imageBleed: string,
    valueText: string,
    valueTitle: string,
    valueeText: string,
    valueIteam: string,
    stabilityText: string,
    stabilityTitle: string,
    stabilityIcons: list(string),
    contacts: list(Employee.t),
  };

  let make = page => {
    headerText1: page##headerText1,
    headerText2: page##headerText2,
    headerBgColor: page##headerTextBgColor,
    funTitle: page##funTitle,
    funText: page##funText##funText,
    goodText: page##goodText##goodText,
    goodTitle: page##goodTitle,
    headerImage: page##headerImage##file##url,
    imageBleed: page##imageBleed##file##url,
    valueText: page##valueText##valueText,
    valueTitle: page##valueTitle,
    valueeText: page##valueeText,
    valueIteam: page##valueIteam##valueIteam,
    stabilityTitle: page##stabilityTitle,
    stabilityText: page##stabilityText##stabilityText,
    stabilityIcons:
      page##stabilityIcons
      ->Belt.Array.map(icon => icon##file##url)
      ->Belt.List.fromArray,
    contacts: Employee.fromArray(page##contacts),
  };
};
