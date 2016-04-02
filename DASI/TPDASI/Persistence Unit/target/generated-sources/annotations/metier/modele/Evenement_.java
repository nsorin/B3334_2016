package metier.modele;

import java.util.Date;
import javax.annotation.Generated;
import javax.persistence.metamodel.ListAttribute;
import javax.persistence.metamodel.SingularAttribute;
import javax.persistence.metamodel.StaticMetamodel;
import metier.modele.Activite;
import metier.modele.Demande;
import metier.modele.Lieu;

@Generated(value="EclipseLink-2.5.2.v20140319-rNA", date="2016-03-15T14:19:44")
@StaticMetamodel(Evenement.class)
public class Evenement_ { 

    public static volatile SingularAttribute<Evenement, Integer> id;
    public static volatile SingularAttribute<Evenement, Lieu> lieu;
    public static volatile SingularAttribute<Evenement, Activite> activite;
    public static volatile SingularAttribute<Evenement, Date> date;
    public static volatile ListAttribute<Evenement, Demande> demandes;

}