import { graphql, useStaticQuery } from 'gatsby'
import React from 'react'
import { Helmet } from 'react-helmet'
import Cases from '../../lib/js/re/pages/Cases'
import Layout from '../Layout'

export default () => {
  const data = useStaticQuery(graphql`
    query Cases {
      contentfulSidaCases {
        headerImage {
          title
          file {
            url
          }
          localFile {
            childImageSharp {
              fluid(maxWidth: 1920, quality: 95) {
                ...GatsbyImageSharpFluid
              }
            }
            publicURL
          }
        }
        headerText1
        headerText2
        headerTextBgColor
        contactTitle
        contacts {
          avatar {
            fluid(maxWidth: 232, quality: 90) {
              src
            }
          }
          email
          name
          short
          title
        }
      }
      allContentfulProjekt(
        filter: { node_locale: { eq: "sv-SE" } }
        sort: { fields: createdAt }
      ) {
        nodes {
          title
          thumbnailImage {
            fixed(width: 450, height: 450) {
              ...GatsbyContentfulFixed_withWebp
            }
          }
          shortDescription
          slug
        }
      }
    }
  `)

  return (
    <Layout>
      <Helmet>
        <html lang="sv" />
        <title>Iteam | Case</title>
        <meta property="og:title" content="Iteam | Case" />
        <meta
          property="og:image"
          content={data.contentfulSidaCases.headerImage.localFile.publicURL}
        />
      </Helmet>
      <Cases
        data={data.contentfulSidaCases}
        projects={data.allContentfulProjekt.nodes}
      />
    </Layout>
  )
}
